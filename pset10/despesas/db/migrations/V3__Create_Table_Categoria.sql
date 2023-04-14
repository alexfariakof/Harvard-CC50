CREATE  TABLE Categoria (
  id INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL,
  idUsuario INTEGER NOT NULL,
  idTipoCategoria INTEGER NOT NULL,
  descricao TEXT NOT NULL);

drop TABLE Categoria;
Select c.id, tc.descricao as tipo, c.descricao From Categoria c Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id where c.idUsuario = 1;

Select sum(valor) from lancamentos where idUsuario = 1;