function _make_ship_at(x, y)
    e = Fuego.Entity();
    e.texture = Fuego.get_texture("/sprites/ship.png")
    e.v.x = x
    e.v.y = y

    Fuego.slayer.foreground:add_entity(e)
end



e = Fuego.Entity()

m = Fuego.slayer.foreground

e.v.x = 20;

m:add_entity(e)

-- e = Fuego.Entity();
-- e.texture = Fuego.Texture(0, "/sprites/ship.png")
-- e.v.x = 256

_make_ship_at(256, 16)
_make_ship_at(128, 16)
_make_ship_at(128, 256)
_make_ship_at(256, 256)

m:add_entity(e)

e = Fuego.Entity();
e.texture = Fuego.get_texture("/sprites/badship1.png")
e.v.x = -300 

m:add_entity(e)

