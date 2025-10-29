function isValidName(name) {
    if(name.trim() === "") alert("Please enter a name");
}

function addRow(){
    const div = document.getElementById('div');

    div.innerHTML = `<div class="form-group">
        <label for="note">Aggiungi note</label>
        <input type="text" id="note" name="note">
        </div>`;
}