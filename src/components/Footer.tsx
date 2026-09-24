export default function Footer(){
  return <footer className="site-footer">
    <img src={`${import.meta.env.BASE_URL}assets/ITA_logo.png`} alt="Logo do ITA" />
    <div className="footer-project">
      <strong>Instituto Tecnológico de Aeronáutica — ITA</strong>
      <span>CE-235 — Sistemas Embarcados de Tempo Real</span>
      <span>SPRB-TR/BD • Time Scrum 2 — Ground Segment</span>
      <span>Sprint 1 • US123 — Telemetry Decoder</span>
      <small>Protótipo acadêmico para demonstração de recepção, desempacotamento e validação de telemetria.</small>
    </div>
    <div className="footer-author"><strong>Desenvolvido por</strong><span>Leonardo Camargo Rossato</span><span>Setembro de 2026</span></div>
  </footer>
}
