//to show result in input box
let screen = document.getElementById("screen");

//all buttons
let buttons = document.querySelectorAll("button");

let screenValue = "";

for (let item of buttons) {
  item.addEventListener("click", (e) => {
    let buttonText = e.target.innerText;
    if (buttonText == "x") {
      buttonText = "*";
      screenValue += buttonText;
      screen.value += buttonText;
    } else if (buttonText == "C") {
      screenValue = "";
      screen.value = screenValue;
    } else if (buttonText == "=") {
      //to evaluate expression
      screen.value = eval(screenValue);
    } else {
      screenValue += buttonText;
      screen.value = screenValue;
    }
  });
}
