print("We are running: "..os.version());
term.setTextColor(colors.cyan);
term.write("testing colors: cyan\n");
print("color should be 512: "..term.getTextColor());
term.setTextColor(0); -- reset
