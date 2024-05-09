var isColorChanged = false;

document.getElementById("checkbox").onclick = function() {
  changeColor();
};

function changeColor() {
  if (!isColorChanged) {
    document.body.style.backgroundColor = "#404040";
    isColorChanged = true;
  } else {
    document.body.style.backgroundColor = ""; // Volta para a cor original (pode ser "#ffffff" ou qualquer outra cor que você definiu)
    isColorChanged = false;
  }
}