  [@react.component]
  let make = () => {
    let _ = ProtectedRoute.useProtectedRoute();
    <Container> <h1> "Protected route"->React.string </h1> </Container>;
  };