<?php

    // configuration
    require("../includes/config.php"); 

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("add_money.php", ["title" => "Add Money"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $money = $_POST["money"];
        $valid_int = preg_match("/^\d+$/", $money);
        if ($valid_int == false)
        {
            apologize("Please enter a positive value.");
        }
        else
        {
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $money, $_SESSION["id"]);
        }
    }
    redirect("/");
?>    