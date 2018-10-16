open BsReactHead.ReactHead;

let component = ReasonReact.statelessComponent("NotFound");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Title> "Not Found"->Util.text </Title>
      <Meta name="description" content="Page not found" />
      <section
        style={
          ReactDOMRe.Style.make(~padding="10px", ~fontFamily="Space Mono", ())
        }>
        <h1> {"Not Found" |> Util.text} </h1>
      </section>
    </>,
};