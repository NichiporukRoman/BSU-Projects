document.getElementById('quizForm').addEventListener('submit', function(event) {
            event.preventDefault();

            const q1 = document.querySelector('input[name="q1"]:checked').value;
            const q2 = document.querySelector('input[name="q2"]:checked').value;
            const q3 = document.querySelector('input[name="q3"]:checked').value;
            const q4 = document.querySelector('input[name="q4"]:checked').value;
            const q5 = document.querySelector('input[name="q5"]:checked').value;
            const q6 = document.querySelector('input[name="q6"]:checked').value;
            const q7 = document.querySelector('input[name="q7"]:checked').value;
            const q8 = document.querySelector('input[name="q8"]:checked').value;
            const q9 = document.querySelector('input[name="q9"]:checked').value;
            const q10 = document.querySelector('input[name="q10"]:checked').value;
            const q11 = document.querySelector('input[name="q11"]:checked').value;
            const q12 = document.querySelector('input[name="q12"]:checked').value;

            let resultMessage = "Based on your answers:<br>";

            if (q1 == "yes" && q2 == "yes") {

            } else if (q1 == "yes" && q2 == "no") {
                if (q3 == "2" && q4 == "yes" && q5 == "2" && q10 == "2" && q11 == "2") {
                    resultMessage += "Playmaker | 10";
                }
            } else if (q1 == "no" && q2 == "yes") {

            } else {
            }

            document.getElementById('resultMessage').innerHTML = resultMessage;
            document.getElementById('resultSection').style.display = 'block';
        });