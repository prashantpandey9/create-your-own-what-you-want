document.getElementById("p2").style.display = "none";
document.getElementById("p1").style.display = "block";
var turn = 0;
var curid = 0;
var ind = [
  [null, null, null],
  [null, null, null],
  [null, null, null],
];
function rungame(id) {
  document.getElementById("dis").style.display = "none";
  document.getElementById("tb").style.display = "block";
  if (turn % 2 == 0) {
    document.getElementById(id).value = "X";
    document.getElementById(id).disabled = true;
    document.getElementById(id).style.color = "#ff7779";
    document.getElementById(id).style.cursor = "not-allowed";
    document.getElementById("p2").style.display = "block";
    document.getElementById("p1").style.display = "none";
    putvalue(1, id, turn);
  } else {
    document.getElementById(id).value = "O";
    document.getElementById(id).disabled = true;
    document.getElementById(id).style.color = "#3cb7f0";
    document.getElementById(id).style.cursor = "not-allowed";
    document.getElementById("p1").style.display = "block";
    document.getElementById("p2").style.display = "none";
    putvalue(0, id, turn);
  }
  turn++;
  curid = id;
  console.log(ind);
}
function putvalue(n, id, turn) {
  //console.log("function called", n, " ", id);
  if (id == 1) {
    ind[0][0] = n;
  } else if (id == 2) {
    ind[0][1] = n;
  } else if (id == 3) {
    ind[0][2] = n;
  } else if (id == 4) {
    ind[1][0] = n;
  } else if (id == 5) {
    ind[1][1] = n;
  } else if (id == 6) {
    ind[1][2] = n;
  } else if (id == 7) {
    ind[2][0] = n;
  } else if (id == 8) {
    ind[2][1] = n;
  } else if (id == 9) {
    ind[2][2] = n;
  }

  //console.log(ind);
  let horizontal = checkHorizontal(id);
  let vertical = checkVertical(id);
  let rightDiagonal = false;
  let leftDiagonal = false;
  if (id == 1 || id == 5 || id == 9) {
    rightDiagonal = checkRightDiagonal(id);
  }
  if (id == 3 || id == 5 || id == 7) {
    leftDiagonal = checkLeftDiagonal(id);
  }
  let decisive = true;
  if (horizontal || vertical || rightDiagonal || leftDiagonal) {
    gameover(turn, decisive);
  } else if (turn == 8) {
    decisive = false;
    gameover(turn, decisive);
  }
}

let index = [
  [0, 0],
  [0, 1],
  [0, 2],
  [1, 0],
  [1, 1],
  [1, 2],
  [2, 0],
  [2, 1],
  [2, 2],
];

function checkHorizontal(id) {
  const r = index[id - 1][0];
  const c = index[id - 1][1];
  for (let i = 0; i < 3; i++) {
    if (ind[i][c] != ind[r][c]) {
      return false;
    }
  }
  return true;
}

function checkVertical(id) {
  const r = index[id - 1][0];
  const c = index[id - 1][1];
  for (let i = 0; i < 3; i++) {
    if (ind[r][i] != ind[r][c]) {
      return false;
    }
  }
  return true;
}

function checkRightDiagonal(id) {
  const r = index[id - 1][0];
  const c = index[id - 1][1];
  for (let i = 0; i < 3; i++) {
    if (ind[i][i] != ind[r][c]) {
      return false;
    }
  }
  return true;
}

function checkLeftDiagonal(id) {
  const r = index[id - 1][0];
  const c = index[id - 1][1];
  const k = ind[r][c];
  if (ind[2][0] == k && ind[1][1] == k && ind[0][2] == k) {
    return true;
  } else {
    return false;
  }
}

function takeBack() {
  document.getElementById(curid).value = "";
  document.getElementById(curid).disabled = false;
  document.getElementById(curid).style.cursor = "pointer";
  turn--;

  const r = index[curid - 1][0];
  const c = index[curid - 1][1];
  ind[r][c] = null;
  console.log(ind);

  if (turn % 2 != 0) {
    document.getElementById("p2").style.display = "block";
    document.getElementById("p1").style.display = "none";
  } else {
    document.getElementById("p1").style.display = "block";
    document.getElementById("p2").style.display = "none";
  }

  document.getElementById("tb").disabled = true;
  document.getElementById("tb").style.cursor = "not-allowed";
}

function gameover(turn, decisive) {
  document.getElementById("go").style.display = "block";
  document.getElementById("again").style.display = "block";
  for (let i = 1; i <= 9; i++) {
    document.getElementById(i).disabled = true;
    document.getElementById(i).style.cursor = "not-allowed";
  }
  document.getElementById("p2").style.display = "none";
  document.getElementById("p1").style.display = "none";
  if (turn % 2 == 0 && decisive) {
    document.getElementById("w1").style.display = "block";
  } else if (turn % 2 == 1 && decisive) {
    document.getElementById("w2").style.display = "block";
  } else if (!decisive) {
    document.getElementById("w0").style.display = "block";
  }
  document.getElementById("tb").disabled = true;
  document.getElementById("tb").style.cursor = "not-allowed";
  document.getElementById("tb").style.display = "none";
}
function playAgain() {
  location = location;
}
