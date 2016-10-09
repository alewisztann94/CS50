<table class="table table-striped">
    <thead>
        <tr>
            <th> Symbol </th>
            <th> Name </th>
            <th> Shares </th>
            <th> Price </th>
            <th> TOTAL </th>
        </tr>
    </thead>    
<?php foreach ($positions as $position): ?>
    <tbody>
        <tr> 
            <td style="text-align:left"><?=$position["symbol"] ?> </td> 
            <td style="text-align:left"><?=$position["name"] ?> </td> 
            <td style="text-align:left"><?=$position["shares"] ?> </td> 
            <td style="text-align:left">$<?=number_format($position["price"], 2, '.', ',') ?> </td> 
            <td style="text-align:left">$<?=number_format($position["total"], 2, '.', ',') ?> </td>
        </tr>
<?php endforeach ?>             
        <tr>
            <td style="text-align:left">CASH</td>
            <td></td><td></td><td></td>
            <td style="text-align:left">$<?=number_format($money, 2, '.', ',') ?> </td>
        </tr>
    </tbody>
</table>