-- sqlite3 movies.db
-- .schema
-- cat 13.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
    Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.
        Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
        Pode haver várias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas o Kevin Bacon nascido em 1958.
        O próprio Kevin Bacon não deve ser incluído na lista resultante.
*/

Select pe.name
  from people p
  inner join stars s on p.id = s.person_id
  inner join movies m on m.id = s.movie_id
  left join people pe on p.id = s.person_id
 where (p.name like 'Kevin%Bacon' and p.birth = 1958) and pe.name is not null
 group by pe.name, pe.title

