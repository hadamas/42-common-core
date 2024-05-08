document.getElementById("dropdown-item").onclick = function() {drop_options()};

function drop_options() {
  document.getElementById("id_dropdown-content").classList.toggle("show");
}