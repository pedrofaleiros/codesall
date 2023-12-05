function getQuery(frase) {
  palavras = frase.split(" ");

  lista = [];

  palavras.forEach((p) => {
    if (p != " " && p != "") {
      lista.push(p);
    }
  });

  frase = lista.join(" ");

  var palavras = frase.split(" ").map((e) => {
    return e;
  });

  query = "";

  palavras.forEach((palavra, index) => {
    query += `titulo:${palavra}`;

    if (index != palavras.length - 1) {
      query += " AND ";
    }
  });

  return query;
}

console.log("\n");
console.log(getQuery("SISTEMA ÚNICO DE SAÚDE BRASILEIRO"));
console.log("\n");
