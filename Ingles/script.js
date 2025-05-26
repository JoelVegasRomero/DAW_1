
function setupQuestion(formId, correctValue, resultId) {
  document.getElementById(formId).addEventListener("submit", function(e) {
    e.preventDefault();
    const selected = document.querySelector(`input[name="${formId.replace('-form','')}"]:checked`);
    const result = document.getElementById(resultId);
    if (!selected) {
      result.textContent = "Selecciona una opción.";
      return;
    }
    result.textContent = selected.value.toLowerCase() === correctValue.toLowerCase()
      ? "¡Correcto!" : `Incorrecto. La respuesta es "${correctValue}".`;
  });
}

setupQuestion("q1-form", "dismiss", "q1-result");
setupQuestion("q2-form", "postularse", "q2-result");
setupQuestion("q3-form", "currículum", "q3-result");

function checkGap(inputId, expected) {
  const userInput = document.getElementById(inputId).value.trim().toLowerCase();
  const result = document.getElementById(inputId + "-result");
  if (userInput === expected.toLowerCase()) {
    result.textContent = "¡Correcto!";
  } else {
    result.textContent = `Incorrecto. La respuesta correcta es "${expected}".`;
  }
}
