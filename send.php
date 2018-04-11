<?php

$nombre

$servername = "localhost";
$username = "monitor";
$password = "monsql";
$dbname = "input_test";

$conn = new mysqli_connect($servername, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Connection failed:" . $conn->connect_error):
}

$nombre = $_POST['nombre'];
$apellido_p = $_POST['apellido_p'];
$apellido_m = $_POST['apellido_m'];

$sql  = "INSERT INTO reviews (name, title, body) 
            VALUES ('".$nombre."','".$apellido_p."','".$apellido_m."')";
            
$result = mysqli_query($conn, $sql);

$conn->close();

?>
  
