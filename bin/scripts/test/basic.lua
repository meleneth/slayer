function ent_info(entity)
  print(entity)
end

e = Fuego.Entity()
print(e.v)
v = e.v
v.x = 20

print(e.v.x)
v.y = 20

e.stats:set('beuno', 4)

ent_info(e)


print("Moo")
print(e.stats:get('beuno'))

