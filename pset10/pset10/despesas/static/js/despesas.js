
var handleSaveDespesa = function() {
    alert('Todo Salvar Despesa');
}

var handleNewDespesa = function() {
    document.querySelector('#data').value = null;
    document.querySelector('#descricao').value = null;
    document.querySelector('#dataVencimento').value = null;
    document.querySelector('#valor').value = null;
    document.querySelector('#categoria').value = '0'
    document.querySelector('#data').focus();
}

var handleListDespesa = function(){
    var doc = document.querySelector('form');
    doc.action = "/despsasList";
    doc.submit();
}
