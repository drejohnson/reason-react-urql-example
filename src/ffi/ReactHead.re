module Title = {
  [@bs.module "react-head"] external title: ReasonReact.reactClass = "Title";
  let make = children => {
    let props = Js.Obj.empty();
    ReasonReact.wrapJsForReason(~reactClass=title, ~props, children);
  };
};

module Meta = {
  [@bs.deriving abstract]
  type jsProps = {
    name: Js.nullable(string),
    property: Js.nullable(string),
    content: Js.nullable(string),
  };
  [@bs.module "react-head"] external meta: ReasonReact.reactClass = "Meta";
  let make = (~name=?, ~property=?, ~content=?, children) => {
    let props =
      jsProps(
        ~name=name->Js.Nullable.fromOption,
        ~property=property->Js.Nullable.fromOption,
        ~content=content->Js.Nullable.fromOption,
      );
    ReasonReact.wrapJsForReason(~reactClass=meta, ~props, children);
  };
};

module Link = {
  [@bs.deriving abstract]
  type jsProps = {
    rel: Js.nullable(string),
    href: Js.nullable(string),
    sizes: Js.nullable(string),
    [@bs.as "type"]
    type_: Js.nullable(string),
    [@bs.as "as"]
    as_: Js.nullable(string),
    media: Js.nullable(string),
    crossorigin: Js.nullable(string),
  };
  [@bs.module "react-head"] external link: ReasonReact.reactClass = "Link";
  let make =
      (
        ~rel=?,
        ~href=?,
        ~sizes=?,
        ~type_=?,
        ~as_=?,
        ~media=?,
        ~crossorigin=?,
        children,
      ) => {
    let props =
      jsProps(
        ~rel=rel->Js.Nullable.fromOption,
        ~href=href->Js.Nullable.fromOption,
        ~sizes=sizes->Js.Nullable.fromOption,
        ~type_=type_->Js.Nullable.fromOption,
        ~as_=as_->Js.Nullable.fromOption,
        ~media=media->Js.Nullable.fromOption,
        ~crossorigin=crossorigin->Js.Nullable.fromOption,
      );
    ReasonReact.wrapJsForReason(~reactClass=link, ~props, children);
  };
};

module Style = {
  [@bs.deriving abstract]
  type jsProps = {
    [@bs.as "type"]
    type_: Js.nullable(string),
    media: Js.nullable(string),
  };
  [@bs.module "react-head"] external style: ReasonReact.reactClass = "Style";
  let make = (~type_=?, ~media=?, children) => {
    let props =
      jsProps(
        ~type_=type_->Js.Nullable.fromOption,
        ~media=media->Js.Nullable.fromOption,
      );
    ReasonReact.wrapJsForReason(~reactClass=style, ~props, children);
  };
};

module HeadProvider = {
  [@bs.deriving abstract]
  type jsProps = {headTags: Js.nullable(string)};
  [@bs.module "react-head"]
  external head_provider: ReasonReact.reactClass = "HeadProvider";
  let make = (~headTags=?, children) => {
    let props = jsProps(~headTags=headTags->Js.Nullable.fromOption);
    ReasonReact.wrapJsForReason(~reactClass=head_provider, ~props, children);
  };
};