const JSEncrypt = require("node-jsencrypt");
const axios = require("axios");
const qs = require("qs");

let encrypt = new JSEncrypt();
let publicKey =
  "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA82h4sA/mAb9O3WCAgxWGb/bei25AVVs0a9oVDUFaeq3G37IYWBBtjuqQKSBsz+uhif92Homx3Y5i+xAERGjy49HrDVjNLNeoGqqAguI9r2t87vU/9KWWBHtflLwWtHkPg/DAhDjETtSOXrKhv/cbXyQmrmXRWqOdJINin92+rKapS40OwDz8IH+Od44+mkiYFiAxUG6HM3oyj0RUeWB4RXf48gNxZdlwg04g+hRhkdapSRhY1BkZqLGQ5carZJS99D9nGroyIaAjOxmRI31/n4ffIQ3ladpr3aQRn8MvLRDxX21c6n4B8vHOYFHt0s72e+IpHZHmMeA083tC8qC3ZQIDAQAB";
let password = "30072001";
encrypt.setPublicKey(publicKey);
let signature = encrypt.encrypt(password);

// console.log(signature);
const formData = {
  username: "2012130067",
  password: signature,
  //   recaptchaResponse: "",
};

const config = {
  headers: {
    "Content-Type": "application/x-www-form-urlencoded",
  },
};

axios
  .post("https://aluno.iesb.br/aluno/auth", qs.stringify(formData), config)
  .then(function (response) {
    console.log(response);
  })
  .catch(function (error) {
    console.log(error);
  });

//   https://aluno.iesb.br/aluno/apix/api/rest/alunos/user/2005152151
//   https://aluno.iesb.br/aluno/apix/api/rest/alunos/user/
//   https://aluno.iesb.br/aluno/config-properties/public-key