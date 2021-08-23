var output = document.getElementById("output");
var button = document.getElementById("button");

function displayOutput() {
    output.textContent = document.getElementById("input").value;
    console.log(text);
}

button.addEventListener("click", displayOutput);