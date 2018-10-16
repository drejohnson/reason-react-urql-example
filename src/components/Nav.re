let component = ReasonReact.statelessComponent("Nav");

let make = _children => {
  ...component,
  render: _self =>
    <nav>
      <Router.Link route=Home> "Home"->Util.text </Router.Link>
      <Router.Link route=About> "About"->Util.text </Router.Link>
    </nav>,
};