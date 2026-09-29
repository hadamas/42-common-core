var isColorChanged = false;

document.getElementById("checkbox").onclick = function() {
  changeColor();
};

function changeColor() {
  if (!isColorChanged) {
    document.body.style.backgroundColor = "#00111c";
    document.getElementById("titulo").style.color = "#ffffff";
    document.getElementById("subtitulo").style.color = "#ffffff";

    isColorChanged = true;
  } else {
    document.body.style.backgroundColor = "#ffffff"; 
    document.getElementById("titulo").style.color = "#000000";
    document.getElementById("subtitulo").style.color = "#000000";

    isColorChanged = false;
  }
}

document.getElementById("dropdown-item").onclick = drop_options;

function drop_options() {
  document.getElementById("id_dropdown-content").classList.toggle("show");
}