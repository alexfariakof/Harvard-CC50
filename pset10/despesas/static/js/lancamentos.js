$(document).ready(function () {
    $('#tableLancamentos').DataTable({
        "language": {
            "Search": "Pesquisar",
            "lengthMenu": "Mostrando _MENU_ registros por página",
            "zeroRecords": "Nada encontrado",
            "info": "Mostrando página _PAGE_ de _PAGES_",
            "infoEmpty": "Nenhum registro disponível",
            "infoFiltered": "(filtrado de _MAX_ registros no total)"
        }
    });
});


var handleEdit = function (idDespesa, idReceita) {

    if (idDespesa === 0) {
        var doc = document.querySelector('form');
        document.querySelector('#idReceita').value = id;
        doc.action = "/receitas";
        doc.method = "POST";
        doc.submit();
    }
    else {
        var doc = document.querySelector('form');
        document.querySelector('#idDespesa').value = id;
        doc.action = "/despesas";
        doc.method = "POST";
        doc.submit();
    }


}

var handleDelete = function (id, idDespesa, idReceita) {

    if (!confirm('Tem certeza que deseja excluir essa ' + ( idDespesa === 0 ? "receita" : "despesa") + '?'))
        return false;

    if (idDespesa === 0) {
        $.ajax({
            url: "receitaDelete",
            type: 'post',
            data: {
                idReceita: id,
            },
            beforeSend: function () {
                $('.modal').show();
            },
            complete: function (jqxhr, txt_status) {
                setTimeout(function () {
                    $('.modal').hide();
                }, 2000);
            },
            success: function (response) {
                if (response.status === '200') {
                    dismissAllALerts();
                    alertSuccess('Receita deletada com sucesso!');
                }
            }
        })
            .done(function (response) {
                $('#tr_' + response.idReceita + '').remove()
                $(window).scrollTop(top);

            })
            .fail(function (jqXHR, textStatus, msg) {
                alertError(jqXHR);
            });
    }
    else {
        $.ajax({
            url: "despesaDelete",
            type: 'post',
            data: {
                idDespesa: id,
            },
            beforeSend: function () {
                $('.modal').show();
            },
            complete: function (jqxhr, txt_status) {
                setTimeout(function () {
                    $('.modal').hide();
                }, 2000);
            },
            success: function (response) {
                if (response.status === '200') {
                    dismissAllALerts();
                    alertSuccess('Despesa deletada com sucesso!');
                }
            }
        })
            .done(function (response) {
                $('#tr_' + response.idDespesa + '').remove()
                $(window).scrollTop(top);

            })
            .fail(function (jqXHR, textStatus, msg) {
                alertError(jqXHR);
            });
    }
}