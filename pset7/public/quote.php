<?php

    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php");
    }

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock to lookup.");
        }
        else
        {
            $s = lookup($_POST["symbol"]);
            if ($s === false)
            {
                apologize("Stock could not be found.");
            }
            render("quote.php", ["s" => $s]);
        }
    }
    
    
    
?>    