const express = require("express");
const mongoose = require("mongoose");
const shortUrl = require("./models/shortUrl");
const app = express();

const PORT = process.env.PORT || 5000;

mongoose
  .connect(
    process.env.MONGOURL,
    {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    }
  )
  .then(() => console.log("Database connected!"))
  .catch((err) => console.log(err));

app.set("view engine", "ejs");
app.use(express.urlencoded({ extended: false }));

app.get("/", async (req, res) => {
  const shortUrls = await shortUrl.find();
  res.render("index", { shortUrls: shortUrls });
});

app.post("/shortUrls", (req, res) => {
  shortUrl.create({ full: req.body.fullUrl });
  res.redirect("/");
});

app.get("/:shortUrl", async (req, res) => {
  const shortUrls = await shortUrl.findOne({ short: req.params.shortUrl });
  if (shortUrls == null) {
    return res.sendStatus(404);
  } else {
    shortUrls.clicks++;
    shortUrls.save();
    res.redirect(shortUrls.full);
  }
});

app.listen(PORT, () => {
  `App is Running on ${PORT}`;
});