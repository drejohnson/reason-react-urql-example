let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <header>
        <div
          style={
            ReactDOMRe.Style.make(
              ~padding="10px",
              ~fontFamily="Space Mono",
              (),
            )
          }>
          <h1>
            <Router.Link route=Home>
              "ReasonReact Urql"->Util.text
            </Router.Link>
          </h1>
          <Nav />
        </div>
      </header>
    </>,
};