var dismissAllALerts = function () {
    var alertList =$('.alert')
    alertList.forEach(function (alert) {    
        alert.remove()
})
}

