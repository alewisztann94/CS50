<?php

    // configuration
    require("../includes/config.php"); 
    $stocks = CS50::query("SELECT * FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell Stocks", "stocks" => $stocks]);
    }

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = lookup($_POST["symbol"]);
        if ($symbol !== false)
        {
            $num = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $symbol["symbol"]);
            $dollars = $symbol["price"] * $num[0]["shares"];
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $dollars, $_SESSION["id"]);
            CS50::query("INSERT INTO history (id, symbol, shares, time, price, status) VALUES(?, ?, ?, NOW(), ?, 'SOLD')", $_SESSION["id"], strtoupper($_POST["symbol"]), $num[0]["shares"], number_format($symbol["price"], 2, '.', ','));
            $del = CS50::query("DELETE FROM portfolio WHERE user_id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        }
        else
        {
            apologize("duh hellow this stock cannot be found. LAK.");
        }
    }    
    redirect("/");
    
?>     