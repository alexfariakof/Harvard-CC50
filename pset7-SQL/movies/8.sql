-- sqlite3 movies.db
-- .schema
-- cat 8.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
Em 8.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Você pode presumir que há apenas um filme no banco de dados com o título Toy Story.
*/

Select p.name
  from people p
 inner join stars s on p.id = s.person_id
 inner join movies m on m.id = s.movie_id
 where m.title like 'Toy Story' group by p.name