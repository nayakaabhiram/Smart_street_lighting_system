function validate(){
    var password = document.getElementById("pass").value;
    var email = document.getElementById("email").value;
  //  var length = document.getElementById("length").value;

    if(email=="123456" && password=="1234"){
        alert("login successful");
        window.location.replace("login.html");
        return false;
    }
    else{
        alert("login failed");
    }
}
