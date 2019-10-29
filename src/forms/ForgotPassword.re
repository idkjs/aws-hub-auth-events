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
    <button onClick className=Styles.button>
      {formType->FormTypes.formTypeToString |> React.string}
    </button>
  </div>;