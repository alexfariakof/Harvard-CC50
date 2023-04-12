
-- sqlite3 DespesasPessoaisDB.db
-- .schema


Select '' as id, lancamentos.*
  From (Select d.idUsuario, data, idCategoria, valor*-1 as valor, 'Despesas' as Tipo, d.id as idDespesa, 0 as idReceita, d.descricao, c.descricao as categoria
          From Despesa d
         Inner Join Categoria c on d.idCategoria = c.id
         where d.idUsuario = 1
           and MONTHdata, 6, 2) = '10'
           and SUBSTRING(data, 1, 4) = '2002'
 union





Select r.idUsuario, data, idCategoria, valor, 'Receitas' as Tipo, 0 as idDespesa, r.id as idReceita, r.descricao, cr.descricao as categoria
  From Receita r
 Inner Join Categoria cr on r.idCategoria = cr.id
 where r.idUsuario = 1
   and data like '%2022-10%'



   ) lancamentos;


Select  SUBSTRING(data, 6, 2) as mes from despesa;
Select  SUBSTRING(data, 1, 4) as ano from despesa;

Select  SUBSTRING(data, 6, 2) as mes from Receita;
Select  SUBSTRING(data, 1, 4) as ano from Receita;

Select * From Categoria;
Select * From Despesa;
Select * From Receita;
select * From lançamento;


Select '' as id, lancamentos.* from
(Select d.idUsuario, data, idCategoria, valor*-1 as valor, 'Despesas' as Tipo, d.id as idDespesa, 0 as idReceita, d.descricao, c.descricao as categoria
  From Despesa d
 Inner Join Categoria c on d.idCategoria = c.id
 where d.idUsuario = 1
   and data like '%2022-10%'
union
Select r.idUsuario, data, idCategoria, valor, 'Receitas' as Tipo, 0 as idDespesa, r.id as idReceita, r.descricao, cr.descricao as categoria
  From Receita r
 Inner Join Categoria cr on r.idCategoria = cr.id
 where r.idUsuario = 1
   and data like '%2022-10%') as lancamentos;


Select cast(CONV(SUBSTRING(uuid(), 4, 4), 16, 10) as UNSIGNED) as id;
Select CURRENT_DATE as data, CURRENT_TIMESTAMP as data_hora ;


CREATE  TABLE _teste2 (
  id INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL,
  idUsuario INTEGER NULL,
  idCategoria INTEGER NULL,
  data DATETIME DEFAULT CURRENT_TIMESTAMP ,
  descricao TEXT NULL,
  valor REAL(10,2) NULL);


SELECT lower(hex(randomblob(16)));
