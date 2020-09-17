open TimerTypes;

let darkThemeId = ID.generate();
let cleanThemeId = ID.generate();

let baseConfig: SidebarForm.output = {
  title: {j|Some title|j},
  description: "Some description",
  time: "05:00",
  theme: cleanThemeId,
};

let initialConfig =
  switch (SidebarForm.Storage.get()) {
  | None => baseConfig
  | Some(Ok(config)) => config
  | Some(Error(error)) =>
    [%log.error
      "Storage#key: " ++ SidebarForm.Storage.key;
      ("Parsing error", error)
    ];

    baseConfig;
  };

let cleanTheme = {
  id: cleanThemeId,
  name: "Timerlab",
  primaryColor: Theme.Colors.(primaryRaw->toHex),
  secondaryColor: Theme.Colors.(backgroundRaw->toHex),
  background: Color("#fff"),
  default: true,
  overlayColor: "",
  opacity: 0.0,
};

let darkTheme = {
  id: darkThemeId,
  name: "Timerlab Dark",
  primaryColor: Theme.Colors.(primaryRaw->toHex),
  secondaryColor: "#FFF",
  background: Color(Theme.Colors.(backgroundRaw->toHex)),
  default: true,
  overlayColor: "",
  opacity: 0.0,
};

let lukinCleanTheme = {
  id: ID.generate(),
  name: "Lukin",
  primaryColor: "#f36",
  secondaryColor: "#00000",
  background: Color("#fff"),
  default: true,
  overlayColor: "",
  opacity: 0.0,
};

let lukinDarkTheme = {
  id: ID.generate(),
  name: "Lukin Dark",
  primaryColor: "#f36",
  secondaryColor: "#fff",
  background: Color("#000"),
  default: true,
  overlayColor: "",
  opacity: 0.0,
};

let defaultThemes = [|
  cleanTheme,
  darkTheme,
  lukinCleanTheme,
  lukinDarkTheme,
|];

let initialValues: ThemeForm.input = {
  name: "",
  primaryColor: cleanTheme.primaryColor,
  secondaryColor: cleanTheme.secondaryColor,
  backgroundColor: "#FFF",
  backgroundImage: "",
  overlayColor: "#000",
  opacity: 0.7,
};
