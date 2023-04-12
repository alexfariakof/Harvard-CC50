CREATE  TABLE Receita (
  id INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL,
  idUsuario INTEGER NOT NULL,
  idCategoria INTEGER NOT NULL,
  data DATETIME DEFAULT CURRENT_DATE ,
  descricao TEXT NULL,
  valor REAL NULL);



Select r.id, r.idUsuario, r.descricao as categoria, tc.descricao as tipo, r.data, r.descricao, r.valor  From Receita r Inner Join Categoria c on r.idCategoria = c.id Inner Join TipoCategoria tc on c.idTipoCategoria = tc.id where r.idUsuario = 1; 
 --  where r.idUsuario = ?