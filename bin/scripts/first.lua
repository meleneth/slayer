e = Fuego.Entity()

m = Fuego.slayer.foreground

e.v.x = 20;

m:add_entity(e)

e = Fuego.Entity();
e.texture = Fuego.Texture(0, "/sprites/ship.png")
e.v.x = 256

m:add_entity(e)

e = Fuego.Entity();
e.texture = Fuego.Texture(0, "/sprites/badship1.png")
e.v.x = -300 
e.v.rotation = 1.0
e.rotation = 64.0

m:add_entity(e)

