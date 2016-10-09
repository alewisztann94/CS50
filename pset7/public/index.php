<?php

    // configuration
    require("../includes/config.php"); 


    $rows = CS50::query("SELECT * FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
    $moneys = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false && $moneys !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => $row["shares"] * $stock["price"], 
                ];
        }         
    }

    $money = $moneys[0]["cash"];    
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "money" => $money]);

?>
