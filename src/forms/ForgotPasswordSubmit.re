open FormStyle;
[@react.component]
let make = (~formType: FormTypes.formType, ~onClick, ~onChange) =>
  <div className=Styles.container>
    <input
      type_="username"
      name="username"
      onChange
      className=Styles.input
      placeholder="Username"
    />
    <input
      type_="confirmationCode"
      name="confirmationCode"
      onChange
      className=Styles.input
      placeholder="Confirmation Code"
    />
    <input
      type_="password"
      name="password"
      onChange
      className=Styles.input
      placeholder="New password"
    />
    <button onClick className=Styles.button>
      {formType->FormTypes.formTypeToString |> React.string}
    </button>
  </div>;