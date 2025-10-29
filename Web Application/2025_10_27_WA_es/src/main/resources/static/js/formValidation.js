function checkNome(value){
    if(value.trim()===''){
        alert('Il nome no può essere vuoto');
    }
}

function checkCognome(value){
    if(value.trim().length<4){
        alert('Il cognome deve essere lungo almeno 4 caratteri');
    }
}

function checkEmail(value){
    if(!value.trim().endsWith('@unical.it') ){
        alert('L\'email inserita deve essere quella istituzionale');
    }
}
