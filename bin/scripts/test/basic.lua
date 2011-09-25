function ent_info(entity)
  print(entity)
end

e = Slayer.Entity()
print(e.v)
v = e.v
v.x = 20

print(e.v.x)
v.y = 20

ent_info(e)

e = 0

