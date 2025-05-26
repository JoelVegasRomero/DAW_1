document.getElementById("quiz-form").addEventListener("submit", function(e) {
  e.preventDefault();
  const answer = document.querySelector('input[name="q1"]:checked');
  const result = document.getElementById("result");
  if (!answer) {
    result.textContent = "Por favor selecciona una opción.";
    return;
  }
  result.textContent = answer.value === "dismiss" ? "¡Correcto!" : "Incorrecto. La respuesta es 'Dismiss'.";
});

function checkGap() {
  const userInput = document.getElementById("gap").value.trim().toLowerCase();
  const gapResult = document.getElementById("gap-result");
  if (userInput === "works") {
    gapResult.textContent = "¡Correcto!";
  } else {
    gapResult.textContent = "Incorrecto. La respuesta correcta es 'works'.";
  }
}
