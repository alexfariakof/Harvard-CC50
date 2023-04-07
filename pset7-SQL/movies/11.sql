-- sqlite3 movies.db
-- .schema
-- cat 11.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
    Em 11.sql, escreva uma consulta SQL para listar os títulos dos cinco filmes com classificação mais alta (em ordem) estrelados por Chadwick Boseman,
        começando com o de classificação mais alta.
        Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
        Você pode presumir que há apenas uma pessoa no banco de dados com o nome de Chadwick Boseman.
*/

Select m.title
  from movies m
 inner join stars s on m.id = s.movie_id
 inner join people p on p.id = s.person_id
 inner join ratings r on r.movie_id = m.id
 where p.name like 'Chadwick%Boseman'
 order by r.rating desc LIMIT 5;
