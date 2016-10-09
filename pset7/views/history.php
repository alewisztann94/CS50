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
<?php foreach ($history as $data): ?>
    <tbody>
        <tr> 
            <td style="text-align:left"><?=$data["status"] ?> </td> 
            <td style="text-align:left"><?=$data["symbol"] ?> </td> 
            <td style="text-align:left"><?=$data["shares"] ?> </td> 
            <td style="text-align:left">$<?=$data["time"] ?> </td> 
            <td style="text-align:left">$<?=number_format($data["price"], 2, '.', ',') ?> </td>
        </tr>
<?php endforeach ?>             
        <tr>
            <td style="text-align:left">CASH</td>
            <td></td><td></td><td></td>
            <td style="text-align:left">$<?=number_format($money, 2, '.', ',') ?> </td>
        </tr>
    </tbody>
</table>