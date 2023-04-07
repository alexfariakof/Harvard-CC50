-- sqlite3 movies.db
-- .schema
-- cat 12.sql | sqlite3 movies.db
-- check50 cs50/problems/2023/x/movies
-- submit50 cs50/problems/2023/x/movies


/*
  Em 12.sql, escreva uma consulta SQL para listar os títulos de todos os filmes estrelados por Johnny Depp e Helena Bonham Carter.
    Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
    Você pode presumir que há apenas uma pessoa no banco de dados com o nome de Johnny Depp.
    Você pode presumir que há apenas uma pessoa no banco de dados com o nome de Helena Bonham Carter.
*/

Select m.title
  from movies m
 left join stars s on m.id = s.movie_id
 left join people p on p.id = s.person_id
 where p.name like 'Johnny%Depp' or p.name like 'Helena%Bonham%Carter'
 group by m.title
 order by m.title 

