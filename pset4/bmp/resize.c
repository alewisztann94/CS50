/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if (n < 0 || n > 100)
    {
        printf("n must be less than or equal to 100.\n");
        return 1;
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // Create duplicate header structs at another address to manipulate for outfile
    
    BITMAPFILEHEADER obf = bf; //if you fread having previously fread before you will transfer garbage to outfile. 
    BITMAPINFOHEADER obi = bi;
    
    // padding for outfile may change due to refactoring of biWidth. SizeImage is the amount of bytes per scanline * height.
    // Scanline bytes is the width + padding * 3 (bytes per pixel)
    // bfSize is the total size of the image file, including the size of the headers (constant of 54 bytes)
    obi.biWidth = bi.biWidth * n;
    obi.biHeight = abs(bi.biHeight) * n * -1; //Original BMP is top-down, so biHeight should be negative to reflect origin being in the top left corner.
    int opadding = (4 - (obi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    obi.biSizeImage = (obi.biWidth * sizeof(RGBTRIPLE) + opadding) * abs(obi.biHeight); //abs is used to get exact int value. 
    obf.bfSize = obi.biSizeImage + 54; 
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&obf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&obi, sizeof(BITMAPINFOHEADER), 1, outptr);

    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //resize vertically
        for (int vert = 0; vert < n; vert++)
        {
            fseek(inptr, i * (bi.biWidth * sizeof(RGBTRIPLE) + padding) + 54, SEEK_SET);
            
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile n times ... you couldn't just change it to n in elements. 
                for (int lak = 0; lak < n; lak++) 
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr); // write 'n' times of the pixel to outfile 
            }
            
            // add new padding value to outfile
            for (int k = 0; k < opadding; k++)
            {
                fputc(0x00, outptr);
            }
            
        }    
        // skip over old padding, if any
        fseek(inptr, padding, SEEK_CUR);
        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
