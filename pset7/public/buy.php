<?php

    // configuration
    require("../includes/config.php"); 

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy Stocks"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = lookup($_POST["symbol"]);
        $shares = preg_match("/^\d+$/", $_POST["shares"]);
        if ($shares == false)
        {
            apologize("Please enter a non-negative integer value for shares.");
        }
        else if ($symbol !== false && $shares == true)
        {
            $mon = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            $cash = $mon[0]["cash"];
            $cost = $symbol["price"] * $_POST["shares"];
            if ($cash < $cost)
            {
                apologize("Not enough cash dollhairs.");
            }
            CS50::query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], $_POST["shares"]);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
            CS50::query("INSERT INTO history (id, symbol, shares, time, price, status) VALUES(?, ?, ?, NOW(), ?, 'BOUGHT')", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], number_format($symbol["price"], 2, '.', ',')); 
        }
        else
        {
            apologize("duh hellow this stock cannot be found. LAK.");
        }
    }    
    redirect("/");
    
?>     

