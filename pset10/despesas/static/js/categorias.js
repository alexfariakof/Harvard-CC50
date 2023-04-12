
var handleSaveCategoria = function() {
    alert('Todo Salvar Categoria');
}

var handleNewCategoria = function() {
    document.querySelector('#TipoCategoria').value = 0;
    document.querySelector('#descricao').value = null;
    document.querySelector('#TipoCategoria').focus();
}

var handleListCategoria = function(){
    var doc = document.querySelector('form');
    doc.action = "/categorias";
    doc.method = "POST";
    doc.submit();
}

var handleEdit = function(id){    
    alert('Todo Categoria handleEdit ida = ' + id);
}

var handleDelete = function (id){
    alert('Todo Categoria handleDelete id = ' + id);
}

