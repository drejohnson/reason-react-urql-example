open ReasonUrql;

open ReactHead;

open UrqlClient;

[@bs.module "./serviceWorker"]
external serviceWorker: unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <Provider client> <HeadProvider> <App /> </HeadProvider> </Provider>,
  "root",
);

serviceWorker();

type hot;

[@bs.deriving abstract]
type module_ = {hot: option(hot)};

[@bs.val] external module_: module_ = "module";
[@bs.send] external accept: (hot, unit) => unit = "accept";

switch (module_->hotGet) {
| Some(h) => h->accept()
| _ => Js.log("We are not hot")
};