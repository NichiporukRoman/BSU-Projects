document.getElementById('quizForm').addEventListener('change', function(event) {
    event.preventDefault();

    const first = ["Goalkeeper", "Defender", "Midfield", "Forward"];
    const second = ["Physical", "Technical", "Intelligent", "Creative", "Workhorse"];

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

    let resultMessage = "";
    let startOfMessage = "Based on your answers:<br>";

    let pos = "No position provided";
    let playStyle = "No play style found";
    let result = "-";

    // Determine position
    if (q1 == "yes") {
        pos = first[0];
    } else if (q2 == "yes" && q3 == "yes") {
        pos = first[2];
    } else if (q2 == "yes" && q3 == "no") {
        pos = first[3];
    } else if (q2 == "no" && q3 == "yes") {
        pos = first[1];
    }

    // Determine play style
    if (q4 == "no" && q5 == "yes" && q6 == "yes" && q7 == "yes" && q8 == "0" && (q9 == "1" || q9 == "2") && q10 == "0") {
        playStyle = second[0];
    } else if (q4 == "yes" && q5 == "yes" && q6 == "yes" && (q8 == "1" || q8 == "2") && q9 == "1" && q10 == "1") {
        playStyle = second[1];
    } else if (q5 == "no" && q6 == "no" && q8 == "2" && q9 == "0" && q10 == "2") {
        playStyle = second[2];
    } else if (q4 == "yes" && q6 == "yes" && q7 == "no" && q8 == "2" && (q9 == "0" || q9 == "1") && q10 == "2") {
        playStyle = second[3];
    } else if (q4 == "no" && q5 == "yes" && q6 == "yes" && q8 == "1" && q9 == "2" && q10 == "1") {
        playStyle = second[4];
    }

    // Determine result based on position and play style
    if (pos == first[0] && (playStyle == second[0] || playStyle == second[4])) {
        result = "SHOTSTOPPER";
    } else if (pos == first[0] && playStyle == second[1]) {
        result = "SWEEPER";
    } else if (pos == first[0] && (playStyle == second[2] || playStyle == second[3])) {
        result = "CREATIVE KEEPER";
    } else if (pos == first[1] && playStyle == second[0]) {
        result = "CD STOPPER";
    } else if (pos == first[1] && playStyle == second[1]) {
        result = "CB CENTREBACK";
    } else if (pos == first[1] && playStyle == second[2]) {
        result = "CB LIBERO";
    } else if (pos == first[1] && playStyle == second[3]) {
        result = "FMB WINGBACK";
    } else if (pos == first[1] && playStyle == second[4]) {
        result = "FB FLANGBACK";
    } else if (pos == first[2] && playStyle == second[0]) {
        result = "DEFENSIVE MIDFIELDER";
    } else if (pos == first[2] && playStyle == second[1]) {
        result = "ATTACKING MIDFIELDER";
    } else if (pos == first[2] && playStyle == second[2]) {
        result = "REGISTA";
    } else if (pos == first[2] && playStyle == second[3]) {
        result = "PLAYMAKER";
    } else if (pos == first[2] && playStyle == second[4]) {
        result = "BOX-TO-BOX";
    } else if (pos == first[3] && playStyle == second[0]) {
        result = "WINGER";
    } else if (pos == first[3] && playStyle == second[1]) {
        result = "BOX-TO-BOX";
    } else if (pos == first[3] && playStyle == second[2]) {
        result = "NINE AND HALF";
    } else if (pos == first[3] && playStyle == second[3]) {
        result = "FALSE NINE";
    } else if (pos == first[3] && playStyle == second[4]) {
        result = "STRIKER";
    }

    document.getElementById('resultMessage').innerHTML = startOfMessage + pos + "<br>" + playStyle + "<br>" + result + "<br>";
    document.getElementById('resultSection').style.display = 'block';
});