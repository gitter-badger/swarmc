print("We are running: "..os.version());
term.setTextColor(colors.cyan);
term.write("testing colors: cyan\n");
print("color should be 512: "..term.getTextColor());
term.setTextColor(0); -- reset

print(" ");

term.setTextColor(colors.green);
print("Testing AES ");
term.setTextColor(0);

local string = "password"
local password = "[]12232sa34ds"
print("Encrypting string: "..string);
print("password: "..password);
local enc_string = aes.encrypt(password, string);
print("Encrypted Text: "..enc_string);
local dec_string = aes.decrypt(password, enc_string)
print("Decrypted Text: "..dec_string)

if dec_string ~= string then
  print("Not equal :(")
else
  print("Equal! :)")
end

print("Fetch google.com");
print(http.get("http://google.com"));
