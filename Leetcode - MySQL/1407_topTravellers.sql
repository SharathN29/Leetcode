# https://leetcode.com/problems/top-travellers/

select name, sum(ifnull(distance,0)) as travelled_distance
from Users as u
left join Rides as r
on u.id = r.user_id
group by 1
order by sum(ifnull(distance,0)) desc, name;