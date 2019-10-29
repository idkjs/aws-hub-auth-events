open FormStyle;
[@react.component]
let make = (~formType: FormTypes.formType, ~onClick) =>
  <Container>
    <h1> {formType->FormTypes.formTypeToString |> React.string} </h1>
    <button onClick className=Styles.button>
      {"Change Form" |> React.string}
    </button>
  </Container>;