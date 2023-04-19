$(document).ready(function () {


    setTimeout(function() {
        $("#navBrand").addClass('collapse')
    }, 5000);
    
    $('#navbarDisplay').on('mouseover' , function(){
        $("#navBrand").removeClass('collapse');
        setTimeout(function() {
            $("#navBrand").addClass('collapse')
        }, 10000);

    });


    $('#tableLancamentos').DataTable({
        "language": {
            "search": "Pesquisar :",
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
        document.querySelector('#idReceita').value = idReceita;
        doc.action = "/receitas";
        doc.method = "POST";
        doc.submit();
    }
    else {
        var doc = document.querySelector('form');
        document.querySelector('#idDespesa').value = idDespesa;
        doc.action = "/despesas";
        doc.method = "POST";
        doc.submit();
    }


}

var handleDelete = function (element, idDespesa, idReceita) {

    if (!confirm('Tem certeza que deseja excluir essa ' + ( idDespesa === 0 ? "receita" : "despesa") + '?'))
        return false;

    if (idDespesa === 0) {
        $.ajax({
            url: "receitaDelete",
            type: 'post',
            data: {
                idReceita: idReceita,
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
                $(element).parent().remove();
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
                idDespesa: idDespesa,
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
                $(element).parent().remove();
                $(window).scrollTop(top);

            })
            .fail(function (jqXHR, textStatus, msg) {
                alertError(jqXHR);
            });
    }
}

var dismissAllALerts = function () {
    var alertList = $('.alert')
    alertList.each(function () {
        $(this).remove();
    });
}