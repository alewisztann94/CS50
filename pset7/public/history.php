<?php

    // configuration
    require("../includes/config.php"); 
    $rows = CS50::query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
    if ($rows !== false)
    {
        foreach ($rows as $row)
        {
            {
                $data[] = [
                    "price" => $row["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"],
                    "time" => $row["time"],
                    "status" => $row["status"]
                    ];
            }         
        }
    }
    $moneys = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    $money = $moneys[0]["cash"];    
    
    render("history.php", ["history" => $data, "title" => "History", "money" => $money]);  
    
?>    