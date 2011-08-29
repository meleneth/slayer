print("Script from file")
print(swig_type(Slayer.console))
print(Slayer.console)
print("<< RESULT >>")
print("Script from file2")
c = Slayer.console
c:log("JUMP DOG LAZY FOX")

print(" -- Slayer --")
print(Slayer)
print(" -- Slayer.console --")
print(Slayer.console)
print("<< Slayer >>")
for k, v in pairs(Slayer) do print(k, v) end
print("<<END>>")
print("<< Slayer.console >>")
e = Slayer.console
print(e)
for k, v in pairs(e) do print(k, v) end
print("<<END>>")
Slayer.console.log("Log message from script to console")
print("End of script from file")

