window.onload = function()
{
    document.querySelector("#new").addEventListener("click", newTodo);
    ft_list = document.querySelector("#ft_list");
    if ((document.cookie))
    {
        var keyValuePairs = document.cookie.split(';');
        for(var i = 0; i < keyValuePairs.length; i++)
        {
            var value = keyValuePairs[i].substring(keyValuePairs[i].indexOf('=')+1);
            addTodo(value);
        }
    }
};

function setCookie(name, value, days)
{
    var date = new Date();
    date.setTime(date.getTime() + (days*24*60*60*1000));
    var expires = "expires="+ date.toUTCString();
    document.cookie = name + "=" + value + ";" + expires + ";path=/";
}

function newTodo()
{
    var todo = prompt("Remplis le champs, toi même tu sais ce qu'il se passera", '');
    if (todo !== '' && todo)
    {
        addTodo(todo);
    }
}

function addTodo(todo)
{
    var div = document.createElement("div");
    div.innerHTML = todo;
    div.addEventListener("click", deleteTodo);
    ft_list.insertBefore(div, ft_list.firstChild);
}

function deleteTodo()
{
    if (confirm("Veux tu réellement me supprimer ? Réfléchis bien ..."))
    {
        this.parentElement.removeChild(this);
    }
}